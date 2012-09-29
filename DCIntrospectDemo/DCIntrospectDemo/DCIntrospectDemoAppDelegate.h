//
//  DCIntrospectDemoAppDelegate.h
//
//  Created by Domestic Cat on 29/04/11.
//

#import <UIKit/UIKit.h>

@class DCIntrospectDemoViewController;

@interface DCIntrospectDemoAppDelegate : NSObject <UIApplicationDelegate>
{
}

@property (nonatomic, strong) IBOutlet UIWindow *window;
@property (nonatomic, strong) IBOutlet DCIntrospectDemoViewController *viewController;

@end
