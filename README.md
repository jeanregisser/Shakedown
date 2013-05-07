# Shakedown

Simple, in-app bug reporting for human beings.

![](http://f.cl.ly/items/0j2h3j380R3I3W213R3O/Screen%20Shot%202013-04-23%20at%202.42.28%20AM.png) ![](http://f.cl.ly/items/1o3D1s1y3P060L2p1P3D/Screen%20Shot%202013-04-23%20at%202.43.08%20AM.png) ![](http://f.cl.ly/items/1n0s22163r2V0C3I452h/Screen%20Shot%202013-04-23%20at%202.43.46%20AM.png)

## Setup

To get going, just clone the repo and drag the contents of your repository into your project, and call `[SHDShakedown sharedShakedown]` at launch. 

## Triggers

By default, Shakedown will begin listening for shake events automatically on debug builds. You can also call `showButton` on SHDShakedown, which will display a button in the status bar of the application (if it has one).

### Reporting Method

It is highly recommended to configure a reporter to suit your specific needs.

#### Configuring the Reporter

For example, you can configure the email reporter like so:

    SHDShakedownEmailReporter *reporter = [[SHDShakedownEmailReporter alloc] init];
    reporter.recipient = @"bugs@test.com";
    [SHDShakedown sharedShakedown].reporter = reporter;

Various reporters will have different things to configure. For example, one that posts to on online service may need an API key or login credentials, or what project to pust bugs to.

##### Included Reporters

- [JIRA](http://www.atlassian.com/software/jira/overview)
- [YouTrack](http://www.jetbrains.com/youtrack/index.jsp)
- [Pivotal](http://www.pivotaltracker.com/) - ([@jeanregisser](https://github.com/jeanregisser))

### Supported iOS Versions

Shakdown works on iOS 5.0 and up.

### A note on ARC

Shakedown uses ARC. To get things working in a non-ARC project, set the `-fobjc-arc` compiler flag on all the files prefixed with `SHD`.

### Private API Usage & Preprocessor Flags

Shakedown uses the private API `UIGetScreenImage()`. This allows us to capture whatever's on the screen (including some fancier OpenGL stuff), but is not permitted by Apple in the App Store. The relevant calls are wrapped in an `#ifdef DEBUG` call, so it will be compiled out in App Store builds, but please be aware of it. Shakedown will, by default only initialize on builds with the `DEBUG` flag set. If you want to do a Release build with Shakedown enabled (for example, for TestFlight), you can define an `ADHOC` preprocessor flag.
