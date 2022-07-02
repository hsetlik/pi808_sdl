# Component GUI system

## Component class

    - Must be nest-able
    - Should be able to size either responsively or based on discrete rect
  
## Window class

    - Owns a tree of components
    - Renders each to the appropriate spot on the screen
    - Respect z-index
    - Virtual functions: renderWindow, handleEvent, render
