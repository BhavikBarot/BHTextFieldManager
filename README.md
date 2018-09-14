<p align="center">
  <img src="https://github.com/BhavikBarot/BHTextFieldManager/blob/master/res/BHTextFieldManagerIcon.png" alt="Icon"/>
</p>
<H1 align="center">BHTextFieldManager</H1>


BHTextFieldManagerDemo
==========================
<a href="https://imgflip.com/gif/2cf9zt"><img src="https://i.imgflip.com/2cf9zt.gif" title="made at imgflip.com"/></a>




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

2) set the textfields/textviews and give a tag from 101 to N in order to navigate the textfields sequance.

3) delegate the textfields and textviews.

4) Setup the framework and see the demo projects for full usage and installation.

5) For the setup and setting up the framework use other methods.


***Objective C***

```

ViewController.h
--------------------------------

#import <UIKit/UIKit.h>
#import <BHTextFieldManager/BHTextFieldManager.h>

@interface ViewController : UIViewController<UITextFieldDelegate,UITextViewDelegate,BHTextFieldManagerDelegate>

@end

ViewController.m
---------------------------------
#import "ViewController.h"

@interface ViewController ()
{
    BHTextFieldManager *BHFramework;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    //Setup the BHTextFieldManager.
    BHFramework = [[BHTextFieldManager alloc] init];
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

//TODO: BHTextFieldManagerDelegate Methods
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

//Error Showing Method
-(void)isErrorOrNot:(BOOL)isError withError:(NSString *)error {
    //You will get the error here and you can pull/comment to me on github.
    NSLog(@"Error: %@",error);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
```

***Swift***

Note: For swift you also can make Bridging Header file and can directly use anywhere and use bellow code.

```
import UIKit
import BHTextFieldManager

class ViewController: UIViewController ,UITextFieldDelegate ,UITextViewDelegate ,BHTextFieldManagerDelegate{

    var BHFramework = BHTextFieldManager() //allocation

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

    //TODO: BHTextFieldManagerDelegate Methods
    func upKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Up Button Clicked")
    }
    func downKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Down Button Clicked")
    }
    func doneKeyBoardBtn(_ sender: Any!) {
        print("Sender's First Responder is Resign, and Done Button Clicked")
    }
    
    //Error Showing Method
    func isErrorOrNot(_ isError: Bool, withError error: String?) {
        //You will get the error here and you can pull/comment to me on github.
        print("Error: \(error ?? "Error")")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
```

NOTE
---
Please note there is a two types of framework files. One is only for iPhone Device/Generic Devices, and second is run on both iPhone Device/Simulator. When you publish or archive the app please use or rplace the framework to "FrameworkForDeviceOnly" framework file otherwise it creates an error for architecture.

SOLUTION
--------
To remove that replacement of the framework you can simply write bellow script in the run script and use Universal Framework.
```
#!/bin/sh
#  Script.sh
#
#  Created by Bhavik's Mac on 18/07/18.
#  Copyright © 2018 Bhavik Barot. All rights reserved.

APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

# This script loops through the frameworks embedded in the application and
# removes unused architectures.
find "$APP_PATH" -name 'BHTextFieldManager.framework' -type d | while read -r FRAMEWORK
do
FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS
do
echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
done

echo "Merging extracted architectures: ${ARCHS}"
lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"
rm "$FRAMEWORK_EXECUTABLE_PATH"
mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done
```

#### Adding Run Script for Framework

1) Create new run script:
        Select the Project, Choose Target → Project Name → Build Phase → Press “+” and Add the Run Script.

![screen shot 2018-09-14 at 2 35 15 pm](https://user-images.githubusercontent.com/39043956/45541655-4f672900-b82d-11e8-916d-d7efb1d7cb4d.png)

2) Write above script in the run script box.

![screen shot 2018-09-14 at 2 35 58 pm](https://user-images.githubusercontent.com/39043956/45541786-95bc8800-b82d-11e8-94bb-cc069e21fe1c.png)

LICENSE
---
Distributed under the MIT License.

Contributions
---
You can contribute through pull requests and issues on GitHub.

Author
---
Bhavik Barot , email at: barotbhavik23@gmail.com
