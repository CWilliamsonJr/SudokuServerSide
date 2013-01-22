
$(function(){  // Loads the javascript when the page is done loading.
    
   $("form").submit(function(){  
              $.post("includes/process.php", $("form").serialize(),function(output){ // sneds the gameboard to be processed
                  $("#errors").html(output)
            
              })             
       return false; 
   })   
   
  $("#puzzle").bind("click",function(){  // reloads the page.
       location.reload(true);
       return false;
   })  
});


