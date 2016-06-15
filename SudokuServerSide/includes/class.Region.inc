<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Deals with the hiding of the of values in each region.
 *
 * @author Clarence
 */
class Region {
    static private $region_1 = array(1,2,3,10,11,12,19,20,21);
    static private $region_2 = array(4,5,6,13,14,15,22,23,24);
    static private $region_3 = array(7,8,9,16,17,18,25,26,27);
    static private $region_4 = array(28,29,30,37,38,39,46,47,48);
    static private $region_5 = array(31,32,33,40,41,42,49,50,51);
    static private $region_6 = array(34,35,36,43,44,45,52,53,54);
    static private $region_7 = array(55,56,57,64,65,66,73,74,75);
    static private $region_8 = array(58,59,60,67,68,69,76,77,78);
    static private $region_9 = array(61,62,63,70,71,72,79,80,81);
    static private $hiddenValuesArray = [];
    /**
     * 
     * 
     * @global Cell $gameArray
     */
    public static function Hide(){
        global $gameArray;
        //$hiddenValues = [];
        $regionAll = array(static::$region_1,static::$region_2,static::$region_3,static::$region_4,
            static::$region_5,static::$region_6,static::$region_7,static::$region_8,static::$region_9);
         
        
         for($i=0; $i < (count($regionAll));$i++){
             
             $arrayTemp = $regionAll[$i];
             $temp1 = mt_rand(3,7);             
             for($j=0; $j < $temp1; $j++){
                shuffle($arrayTemp);
                $hiddenValues[] = array_pop($arrayTemp);
             }             
         }
        static::$hiddenValuesArray = $hiddenValues; 
        for ($i=0;$i < count($hiddenValues); $i++ ){
            
            $gameArray[$hiddenValues[$i]]->_setIsHidden(TRUE); 
            //$gameArray[$hiddenValues[$i]] = $gameArray[$hiddenValues[$i]]->__ToString();
      }
    }
    /**
     * 
     * @return bool
     */
    public static function _getHiddenVaulesArray(){
        return static::$hiddenValuesArray;
    }
}

?>
