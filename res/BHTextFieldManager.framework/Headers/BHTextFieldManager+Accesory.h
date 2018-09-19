//
//  BHTextFieldManagerAccesoryView.h
//  BHTextFieldManager
//
//  Created by Bhavik's Mac on 3/8/18.
//  Copyright © 2018 Bhavik Barot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class BHTextFieldManager;

typedef NS_ENUM(NSInteger, senderIDType) {
    TextField = 1,
    TextView
};

@protocol BHTextFieldManagerDelegate <NSObject>
@optional
/*
 Do Something after Up Button Click Event, It is Called After Resgining the FirstResponder of the Object.
*/
-(void)upKeyBoardBtn:(id)sender isLastTextFieldOrTextView:(enum senderIDType)type;

/*
 Do Something after Down Button Click Event, It is Called After Resgining the FirstResponder of the Object.
 */
-(void)downKeyBoardBtn:(id)sender isLastTextFieldOrTextView:(enum senderIDType)type;

/*
 Do Something after Done Button Click Event, It is Called After Resgining the FirstResponder of the Object.
 */
-(void)doneKeyBoardBtn:(id)sender isLastTextFieldOrTextView:(enum senderIDType)type;
/*
 This will aknowladge what is the error in you implementation if any occure.
 */
-(void)isErrorOrNot:(BOOL)isError withError:(nullable NSString *)error;

@end

@interface BHTextFieldManager : NSObject
@property (nonatomic, weak) IBOutlet id <BHTextFieldManagerDelegate> delegate;
/*
 To set Enable the framework for the ViewController/View Object.
*/
-(void)setEnable:(UIView*)view;

/*
 Setup the InputAccessoryView to TextFields/TextViews for Giving Navigation View to TextFields/TextViews.
*/
-(UIView *)setInputViewForKeyboard:(id)getID;

/*
 To set Keyboard Distance From TextField. Default it 10.0
*/
-(void)setKeyboardDistanceFromTextField:(CGFloat)distance;

/*
 To Show/Enable the Up-Down Navigation Button. Default is Yes.
*/
-(void)isShowUpDownBtn:(bool)isEnable;

/*
 To Set the Color of Up-Down Navigation Button. Default is Black.
 */
-(void)colorForUpDownArrow:(UIColor*)color;

/*
 To Set the Color of Done Button Text. Default is Black.
 */
-(void)colorForDoneButtonText:(UIColor*)color;

/*
 To Set the Color of Background View. Default is Light Gray.
 */
-(void)colorForBackgroundView:(UIColor*)color;

/*
 To Set the Title of Done Button. Default is "Done".
 */
-(void)setDoneButtonTitle:(NSString*)title;
@end
