var counter = 1;
setInterval(function(){
    document.getElementById('radioBtn' + counter).checked = true; 
    counter++;
    
    if(counter > 8){
        counter = 1;
    }
}, 3000);