//
//  AHKActionSheet.h
//  AHKActionSheetExample
//
//  Created by Arkadiusz on 08-04-14.
//  Copyright (c) 2014 Arkadiusz Holko. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AHKActionSheetButtonType) {
    AHKActionSheetButtonTypeDefault = 0,
    AHKActionSheetButtonTypeDestructive
};

@class AHKActionSheet;
typedef void(^AHKActionSheetHandler)(AHKActionSheet *actionSheet);

@interface AHKActionSheet : UIView <UIAppearanceContainer>

// Appearance
@property (nonatomic) CGFloat blurRadius UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) UIColor *blurTintColor UI_APPEARANCE_SELECTOR;
@property (nonatomic) CGFloat blurSaturationDeltaFactor UI_APPEARANCE_SELECTOR;
@property (nonatomic) CGFloat buttonHeight UI_APPEARANCE_SELECTOR;
// enabled when value is equal to @YES (enabled by default)
@property (strong, nonatomic) NSNumber *automaticallyTintButtonImages UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) UIColor *separatorColor UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) UIColor *selectedBackgroundColor UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) NSDictionary *buttonTextAttributes UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) NSDictionary *destructiveButtonTextAttributes UI_APPEARANCE_SELECTOR;
@property (strong, nonatomic) NSDictionary *cancelButtonTextAttributes UI_APPEARANCE_SELECTOR;

/// Called on every type of dismissal (tapping on "Cancel" or swipe down or flick down).
@property (strong, nonatomic) AHKActionSheetHandler cancelHandler;
@property (strong, nonatomic) NSString *cancelButtonTitle;
@property (copy, nonatomic) NSString *title;
/// Will be shown above the first button (if the title isn't set).
@property (strong, nonatomic) UIView *headerView;

@property (weak, nonatomic, readonly) UIWindow *previousKeyWindow;

- (instancetype)initWithTitle:(NSString *)title;
- (void)addButtonWithTitle:(NSString *)title image:(UIImage *)image type:(AHKActionSheetButtonType)type handler:(AHKActionSheetHandler)handler;
- (void)addButtonWithTitle:(NSString *)title type:(AHKActionSheetButtonType)type handler:(AHKActionSheetHandler)handler;
- (void)show;
- (void)dismissAnimated:(BOOL)animated;

@end
