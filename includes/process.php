<?php   
    require_once 'class.Cell.inc';
    session_start();    
    $result = SolveGame();
    function SolveGame(){
       $gameArray = $_SESSION["GameBoard"];     
        $errors = 0; // contains the number of errors on the board
        foreach($_POST as $postkey => $postvalue){           
            if(!is_numeric($postkey)) continue; 
            $tempCellValue = trim($gameArray[$postkey]->_getCellValue());
            $stringcompare = strcmp($tempCellValue, $postvalue); // compares the two strings.
                 if($stringcompare != 0){ //checking the returned value from strcmp.                     
                     $errors++;                 
                }                  
        }
        if ($errors >= 1){        
           if($errors == 1){
               return "You have an error on the board"; 
            }
           echo "You have multiple errors on the board.";
        }  else {       
            echo "YOU WIN";
        }        
    }
    echo $result;
?>
