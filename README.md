# iOSDeviceScreenAdapter

A simple class that help you identify device's screen when coding, with some useful extensions inside.

All method are implemented as class methods, It may seem easier to use.

Now with CocoaPods compatible

# Install Manually:

1. Simply copy the class file into your project.

2. import the header file.

# Install with CocoaPods:

1. add this line into your Podfile:

    pod 'iOSDeviceScreenAdapter', '~> 1.0.2'

2. pod install

3. import the framework with

    import <iOSDeviceScreenAdapter/DeviceScreenAdapter>

# Usage:

1. Initialize the class when your app is start.
```
    [DeviceScreenAdaptor sharedAdaptor]
```

2. To use adaptedValue method, rewirte the getter of property developStrandardScreenType to your current develop device screen type.

(Recommanded) Alternative: If you are using version 1.0.3 just simply call the method 
```
    - (void)setDeveloperScreenType:(DeviceScreenType)type
```

to set your develop device in Appdelegate.m

# Methods Available:

![alt text](/ClassMethod.png)

# PredefinedFunctions:
![alt text](/PredefinedFunctions.png)

# UpdateLog:
### 1.0.3 released
#### 1.fixed unset develop device bug.
#### 2.Add predefined functions to call methods in a swifter way.
#### 3.Changed stupid way of changing develop device screen type.
