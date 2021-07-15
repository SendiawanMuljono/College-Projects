$(document).ready(function(){
    $(".fRight").on("click", goToNextImgFeature)
    $(".fLeft").on("click", goToPrevImgFeature)

    setInterval(function(){
        $(".highlightSlide").animate({right: $(".hImage").width()}, 1000, function(){
            $(".hImage:first-child").appendTo(".highlightSlide")
            $(".highlightSlide").css("right", "")
        })
    }, 1500)
})

function goToNextImgFeature(){
    var currImg = $(".on")
    var nextImg = currImg.next()
    if(nextImg.length){
        currImg.removeClass("on").css("z-index", -5)
        nextImg.addClass("on").css("z-index", 5)
    }
    $("#fImage:first-child").appendTo(".slideFeature")
    $(".slideFeature").css("right", "")
}

function goToPrevImgFeature(){
    var currImg = $(".on")
    var prevImg = currImg.prev()
    if(prevImg.length){
        currImg.removeClass("on").css("z-index", -5)
        prevImg.addClass("on").css("z-index", 5)
    }
    $("#fImage:last-child").prependTo(".slideFeature")
    $(".slideFeature").css("left", "")
}

// function goToNextImgHighlight(){
//     var currImg = $(".live")
//     var nextImg = currImg.next()
//     if(nextImg.length){
//         currImg.removeClass("live").css("z-index", -5)
//         nextImg.addClass("live").css("z-index", 5)
//     }
//     $("#hImage:first-child").appendTo(".highlightSlide")
//     $(".highlightSlide").css("right", "")
// }

// function goToPrevImgHighlight(){
//     var currImg = $(".live")
//     var prevImg = currImg.prev()
//     if(prevImg.length){
//         currImg.removeClass("live").css("z-index", -5)
//         prevImg.addClass("live").css("z-index", 5)
//     }
//     $("#hImage:last-child").prependTo(".highlightSlide")
//     $(".highlightSlide").css("left", "")
// }