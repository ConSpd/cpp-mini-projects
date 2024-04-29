# App Manager
The application personifies an app manager for mobile applications and games. Specifically it deals with:

1. **Games** that contain the following information
   - ID
   - Name
   - Minimal OS version
   - Manufacturer
   - Online / Offline
   - Genre
   - Ratings
   - Price
  
2. **Office Applications** that contain the following information
   - ID
   - Name
   - Minimal OS version
   - Manufacturer
   - List of files that it can work with
   - Ratings
   - Price
  
The system records the data at an instance of `AppSystem` Class which it has the following functions:
- Maintains a single list of all applications
- It provides methods for importing a new application, importing a new manufacturer, and importing a user rating into an application.
- Provides methods of modifying the data recorded.
- Deletes all applications of a manufacturer which has been deemed to be 'malicious'.
- Returns list of free desktop apps and list of games that have an average rating > of 4.
- Prints a full report, in a given channel, of all the data of all applications on the system. Included in the report are the app ratings data. The format of the report for each application will depend on the category of the application.
- Store/retrieve to/from file all system data
