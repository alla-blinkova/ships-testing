There are 3 main folders here:
 - 'Battleships/Strategy' -- contains the strategy to be tested
 - 'BSTest/mpr' -- contains the set of test cases
 - 'TAT' -- Test Automation Toolset

Initial steps:
1. Setup TCL 8.4 (included)
2. Add environment variables (pay attention to slash '/' and no white spaces)
 - SIC_PATH (like "D:/Home/Work/TAT/" )
 - BATTLESHIPS (like "D:/Home/Work/Battleships/")
 - TELELOGIC_SDL_DIR (like "D:/Tools/SDL_TTCN_Suite4.4/")
3. Run 'tat.tcl' from TAT directory. The next steps should be done from the TAT GUI.
4. Open project 'config.sic' from 'BSTest'
5. See the test cases and signals (to be added/replaced with new).
6. Do 'Project --> Run'.
7. In 'BSTest/verdict' folder should be the log-result of run.

Test case can be created/edited via MSC Editor (part of Telelogic Tau).