<p align="center">
  <img src="https://github.com/BhavikBarot/BHTextFieldManager/blob/master/res/BHTextFieldManagerIcon.png" alt="Icon"/>
</p>
<H1 align="center">BHTextFieldManager</H1>


Often while developing an app the iPhone keyboard slide up and cover the `UITextField/UITextView`. `BHTextFieldManager` allows you to prevent issues of the keyboard sliding up and cover `UITextField/UITextView` without needing you to enter any extra code. To use `BHTextFieldManager` you simply need to add Framework file to your project.


#### Key Features

1) `Set the keyboard navigation for perticular view`

2) `It is worked even the textfields/textviews are placed at different different views and any sequance because it is works on textfield's tag.`

3) `Get the Up,Down and Done button's actions by the delegates for performing tasks`

4) `Set Arrow button and Done button and background view colors according to your theme`

5) `Set done button's text as you want and hide and shows up down arrows as your need.`


`BHTextFieldManager` works on all orientations, and with the toolbar. There are also nice optional features allowing you to customize the distance from the text field, add the next/previous done button as a keyboard UIToolbar and set the colors, also can change the text of done button. You can get the all up/down and done button's click event by calling the delegates. you can hide and show up/down arrows as your need.

Installation
==========================


#### Installation

1)  (i) Create a new project:
        File → New → Project. Select iOS and choose “Single View Application” and click “Next”. And set options like Product Name, Team, etc. and create the Project.

![1](https://user-images.githubusercontent.com/39043956/40242973-b6855b56-5adc-11e8-9b4e-e780d1b1f741.png)

![2](https://user-images.githubusercontent.com/39043956/40243084-f1152bf2-5adc-11e8-8067-ad0af18083fb.png)


(ii) Set the Framework Dependencies:
        Copy/Drag the Universal Framework to this project.

![3](https://user-images.githubusercontent.com/39043956/40243202-4abdada0-5add-11e8-8b49-e0f31e49ba38.jpg)

While coping the framework in Project Explorer, check “Copy items if needed”.

![4](https://user-images.githubusercontent.com/39043956/40243296-77a5d82e-5add-11e8-8e1a-209569aa536a.jpg)
        
(iii) Select the Project, Choose Target → Project Name → Select General → Scroll to “Embedded Binaries”. Press “+” and Add the framework.

![5](https://user-images.githubusercontent.com/39043956/40243430-d81c19e8-5add-11e8-843e-ca840c9b7462.jpg)

![6](https://user-images.githubusercontent.com/39043956/40243487-f756405e-5add-11e8-9545-51f317a417cb.jpg)

2) set the textfields/textviews and give a tag from 1 to N in order to navigate the textfields sequance.

3) delegate the textfields and textviews.

4) Setup the framework and see the demo projects for full usage and installation.

5) For the setup and setting up the framework use other methods.


***Objective C***

```

ViewController.h
--------------------------------

#import <UIKit/UIKit.h>
#import <BHTextFieldManager/BHTextFieldManager.h>

@interface ViewController : UIViewController<UITextFieldDelegate,UITextViewDelegate,BHTextFieldManagerAccesoryViewDelegate>

@end

ViewController.m
---------------------------------
#import "ViewController.h"

@interface ViewController ()
{
    BHTextFieldManagerAccesoryView *BHFramework;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    //Setup the BHTextFieldManager.
    BHFramework = [[BHTextFieldManagerAccesoryView alloc] init];
    BHFramework.delegate = self;
    [BHFramework setEnable:self.view];
}
- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    textField.inputAccessoryView = [BHFramework setInputViewForKeyboard:textField];
}
-(BOOL)textViewShouldBeginEditing:(UITextView *)textView {
    textView.inputAccessoryView = [BHFramework setInputViewForKeyboard:textView];
    return YES;
}

//TODO: BHTextFieldManagerAccesoryViewDelegate Methods
-(void)upKeyBoardBtn:(id)sender {
    //Do Something...
    NSLog(@"Sender's First Responder is Resign, and Up Button Clicked");
}
-(void)downKeyBoardBtn:(id)sender {
    //Do Something...
    NSLog(@"Sender's First Responder is Resign, and Down Button Clicked");
}
-(void)doneKeyBoardBtn:(id)sender {
    //Do Something...
    NSLog(@"Sender's First Responder is Resign, and Done Button Clicked");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
```

***Swift***

Note: For swift make Bridging Header file and write import statement there and can directly use anywhere and use bellow code.

```
import UIKit

class ViewController: UIViewController ,UITextFieldDelegate ,UITextViewDelegate ,BHTextFieldManagerAccesoryViewDelegate{

    var BHFramework = BHTextFieldManagerAccesoryView() //allocation

    override func viewDidLoad() {
    super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

        //Setup the BHTextFieldManager.
        BHFramework.delegate = self
        BHFramework.setEnable(self.view)
    }

    func textFieldDidBeginEditing(_ textField: UITextField) {
        textField.inputAccessoryView = BHFramework.setInputViewForKeyboard(textField)
    }
    func textViewShouldBeginEditing(_ textView: UITextView) -> Bool {
        textView.inputAccessoryView = BHFramework.setInputViewForKeyboard(textView)
        return true
    }

    //TODO: BHTextFieldManagerAccesoryViewDelegate Methods
    func upKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Up Button Clicked")
    }
    func downKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Down Button Clicked")
    }
    func doneKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Done Button Clicked")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
```

NOTES :-
---
Please note there is a three types of framework files. One is only for iPhone Device/Generic Devices, and second is only for Simulator and third is run on both. When you publish or archive the app please use or rplace the framework to "FrameworkForDeviceOnly" framework file otherwise it creates an error for architecture.

LICENSE
---
Distributed under the MIT License.

Contributions
---
You can contribute through pull requests and issues on GitHub.

Author
---
Bhavik Barot , email at: barotbhavik23@gmail.com
