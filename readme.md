DCIntrospect
============

Twitter: [@patr](http://twitter.com/patr)

Our commercial apps: [domesticcat.com.au](http://domesticcat.com.au/apps)

Introspect is small set of tools for iOS that aid in debugging user interfaces built with UIKit.  It's especially useful for UI layouts that are dynamically created or can change during runtime, or for tuning performance by finding non-opaque views or views that are re-drawing unnecessarily.  It's designed for use in the iPhone simulator, but can also be used on a device.


![Introspect Demo Image](http://domesticcat.com.au/projects/introspect/introspectdemo.png)


It uses keyboard shortcuts to handle starting, ending and other commands.  It can also be invoked via an app-wide `UIGestureRecognizer` if it is to be used on the device.

Features:
--------------
* Simple to setup and use
* Controlled via app-wide keyboard commands
* Highlighting of view frames
* Displays a views origin & size, including distances to edges of main window
* Move and resize view frames during runtime using shortcut keys
* Logging of properties of a view, including subclass properties, actions and targets (see below for an example)
* Logging of accessibility properties — useful for UI automation scripts
* Manually call setNeedsDisplay, setNeedsLayout and reloadData (for UITableView)
* Highlight all view outlines
* Highlight all views that are non-opaque
* Shows warning for views that are positioned on non-integer origins (will cause blurriness when drawn)
* Print a views hierarchy to console (via private method `recursiveDescription`) to console

Usage
-----

Before you start make sure the `DEBUG` environment variable is set.  DCIntrospect will not run without that set to prevent it being left in for production use.

Add the `DCIntrospect` class files to your project, add the QuartzCore framework if needed, then call `[[DCIntrospect sharedIntrospector] start]` _after_ `[window makeKeyAndDisplay]`.

Once installed, simply push the space bar to invoke the introspect or then start clicking on views to get info.  You can also tap and drag around the interface.

A a small demo app is included to test it out.

Selected keyboard shortcuts
-----------------------------------------

* Start/Stop: `spacebar`
* Help: `?`
* Print properties and actions of selected view to console: `p`
* Print accessibility properties and actions of selected view to console: `a`
* Toggle all view outlines: `o`
* Toggle highlighting non-opaque views: `O`
* Nudge view left, right, up & down: `4 6 8 2` (use the numeric pad)
* Print out the selected views' new frame to console after nudge/resize: `0`
* Print selected views recursive description to console: `v`

Logging selected views properties
-------------------------------------------------

Pushing `p` will log out the available properties about the selected view.  DCIntrospect will try to make sense of the values it can and show more useful info.  An example from a `UIButton`:

    ** UIRoundedRectButton : UIButton : UIControl : UIView : UIResponder : NSObject **
    
    ** UIView properties **
        tag: 1
        frame: {{21, 331}, {278, 37}} | bounds: {{0, 0}, {278, 37}} | center: {160, 349.5}
        transform: [1, 0, 0, 1, 0, 0]
        autoresizingMask: UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin
        autoresizesSubviews: YES
        contentMode: UIViewContentModeScaleToFill | contentStretch: {{0, 0}, {1, 1}} backgroundColor: (null) (incompatible color space)
        alpha: 1.00 | opaque: NO | hidden: NO | clips to bounds: NO |
        clearsContextBeforeDrawing: YES
        userInteractionEnabled: YES | multipleTouchEnabled: NO
        gestureRecognizers: (null)
    
    ** UIRoundedRectButton properties **
    
    ** Targets & Actions **
        target: <DCIntrospectDemoViewController: 0x4c8c0e0> action: buttonTapped:

Customizing Key Bindings
--------------------------------------

Edit the file `DCIntrospectSettings.h` to change key bindings.  You might want to change the key bindings if your using a laptop/wireless keyboard for development.

To Do
--------

* Add support for arrow keys for nudging views around, and maybe modifier keys for other things also.  If anyone knows how to do this please get in touch.  The iPhone app Prompt by Panic does this so I'm sure it's possible.

License
-----------

Made available under the MIT License.