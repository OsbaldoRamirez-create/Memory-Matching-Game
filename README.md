# Memory-Matching-Game C++

Create a memory matching game based on sports cars with a maximum of 50 cars using 1 and 2 dimensional arrays using C++. User Selects a FIRST square, the theme/face term in the grid square is replaced with corresponding stored term, from the 2-dim array. User selects SECOND square, the term theme/face in the second grid is replaced with the corresponding stored term, from the 2-dim array. The program compares the terms for the selected squares. If they are the same, the terms remain on the screen and can **no** longer be selected. If they are different, the term remain on the screen for 2,4, or 6 seconds, depending on user selection at beginning of the game. After that elapse time, those two grid terms are replaced with the face/them term.

## Menu User Interaction 
- Level of play -- User Selects at start of game
  - 4x4 grid (Easy)
  - 6x6 grid (Moderate)
  - 8x8 grid (Difficult)
- Speed of play -- At start of gane, User selects time interval to display User selected term-pair
  - 2 Seconds (Difficult)
  - 4 Seconds (Moderate)
  - 6 Seconds (Easy)
  
## Create Answer grid with randomly selected terms from theme array
 - At start of the game program places the same face/SportCars theme in ALL visible squares in the 
   visible grid(Real answers not yet visible, only theme name is displayed in all squares).
 - Program selects number of random cars from the 50 available.
   - If a 4x4 grid, randomly pick 8 cars, place 'Sports Cars' theme ** twice ** in 2-Dim array.
   - If a 6x6 grid, randomly pick 18 cars, place'Sports Cars' theme ** twice ** in 2-Dim array.
   - If a 8x8 grid, randomly pick 32 cars, place each 'Sports Cars' theme ** twice ** in 2-Dim 
         array.
## Display the current game state on screen
  - During the course of play, the face/theme term in the display grid is replaced by a  
    corresponding array term, when user selects a grid square
