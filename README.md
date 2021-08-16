# WxWidgets-Darian_Calendar_Tempus-
Release Version 1.0

//-- Introduction-----------------------------------------------------------------------------------------------------------------------//


This is a Calendar that shows the Gregorian(Earth) and Darian(Mars) calendar with many features written in notes section.


//--------------------------------------------------------------------------------------------------------------------------------------//

Build Guide:

This project is made in Microsoft Visual Studio Community 2019 Version 16.10.4
using wxWidgets-3.1.5


For setup, install Visual Studio, download the wxWidgets folder from the official site and build it.
Then, make an empty c++ project where we setup wxwidgets in the project properties.(Recommended to save this project as a template for future wxwidgets projects)
Build the project in both Debug and Release, copy and paste the relevant .dll files into your project debug and release folder.
Then run the project.


I recommend to use this video to setup wxwidgets in Visual Studio and run this project.
Recommended Video for build: https://www.youtube.com/watch?v=EI2taYkErRg&list=PLpHIphr3laQbBLJ8j4iXy8lieaiY9Q10y&index=1&t=4s

Visual Studio: https://visualstudio.microsoft.com/downloads/

WxWidgets:https://www.wxwidgets.org/downloads/

GitHub documentation for wxWidgets:https://github.com/wxWidgets/wxWidgets
Link to install documentations in Git:https://github.com/wxWidgets/wxWidgets/blob/v3.1.2/docs/msw/install.md

//----------------------------------------------------------------------------------------------------------------------------------------//

Notes:
Contains two calendar 
1. Change between the views : Month and Year for both Calendar
2. Set Date and Time for both calendars
3. Menu bar and Tool bar added for many functions
4. The time is updated every second using wxTimer
5. Separate classes are created for both Gregorian Calendar and Darian Calendar with necesary functions
6. Custom Dialog for the set date and set time dialog
7. Next and Previous buttons to easily navigate in both year and month view for both calendars
8. Added quotes for every specific month
9. Status update in Status Bar with the current date in Gregorian shown in statusbar and many more...


//------------------------------------------------------------------------------------------------------------------------------------------//

Tempus

-Bishal Khand Thakuri 076bct018

-Kaushal Gautam 076bct030

-Aadarsh Khatri 076bct002
