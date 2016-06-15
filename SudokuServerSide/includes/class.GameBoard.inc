<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Pulls in the file that will be used and populates $gameTable,$gameArray,$answerKey variables.
 *
 * @author Clarence
 */
class GameBoard {
     static private $filename = "SudokuServerSide/puzzles/" ;
     static private $handle;
     static private $filesize;
     static private $buffer;
     const LOW = 1 ;
     const HIGH = 7 ;
     const MAX = 81;
     /**
      *
      *
      * @global Cell $gameArray
      * @global Array $answerKey
      * @throws Exception
      */
     static public function MakeBoard(){
         static::makeFileName();
         static::$filesize = filesize(static::$handle);
         global $gameArray,$answerKey;

         try {
                if (file_exists(static::$filename)){
                   static::$handle = fopen(static::$filename, "r");
                   static::$filesize = filesize(static::$filename);

           }else{
                throw new Exception("There was no file or it can't be read");
             }
           } catch (Exception $e){
                print_r($e->getMessage());
                printf("</br >");
                print_r(static::$filename);
        }

         $i = 1;

         while(!feof(static::$handle)){ // Loops though the open file

             static::$buffer = fgetss(static::$handle, static::$filesize);
             $gameArray[$i]->_setCellValue(static::$buffer);
             $answerKey[$i] = $gameArray[$i]->__ToString();
             $i++;
         }

         fclose(static::$handle);  // closes file

    }
    static private function makeFileName(){ // Generates the file name
        static::$filename.= "Board";
        static::$filename.= (string)(mt_rand(static::LOW,static::HIGH));
        static::$filename.=".txt";
    }
    /**
     *
     * @return string
     */
    static public function _getFileName(){
        return static::$filename;
    }
}
?>
