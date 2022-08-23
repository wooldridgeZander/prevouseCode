var currentDate = new Date(),
      day = currentDate.getDate(),
      month = currentDate.getMonth() + 1,
      year = currentDate.getFullYear();
  document.write(day + "/" + month + "/" + year)

  function brokenW() {
      var Image_Id = document.getElementById('brokenW');
      if (Image_Id.src.match("jewly_img/broken_w.jpg")) {
          Image_Id.src = "jewly_img/broken_w_1.jpg";
      }
      else {
          Image_Id.src = "jewly_img/broken_w.jpg";
      }
  }

  function eyeFlower() {
      var Image_Id = document.getElementById('eyeFlower');
      if (Image_Id.src.match("jewly_img/eye_flower.jpg")) {
          Image_Id.src = "jewly_img/eye_flower_1.jpg";
      }
      else {
          Image_Id.src = "jewly_img/eye_flower.jpg";
      }
  }

  function rRing() {
      var Image_Id = document.getElementById('rRing');
      if (Image_Id.src.match("jewly_img/R_ring.jpg")) {
          Image_Id.src = "jewly_img/ring.jpg";
      }
      else {
          Image_Id.src = "jewly_img/R_ring.jpg";
      }
  }

  function sStone() {
      var Image_Id = document.getElementById('sStone');
      if (Image_Id.src.match("jewly_img/secret_of_the_stone.jpg")) {
          Image_Id.src = "jewly_img/secret_of_the_stone_1.jpg";
      }
      else {
          Image_Id.src = "jewly_img/secret_of_the_stone.jpg";
      }
  }

  function sesioty() {
      var Image_Id = document.getElementById('sesioty');
      if (Image_Id.src.match("jewly_img/sesioty.jpg")) {
          Image_Id.src = "jewly_img/sesioty_1.jpg";
      }
      else {
          Image_Id.src = "jewly_img/sesioty.jpg";
      }
  }

  function prot() {
      var Image_Id = document.getElementById('prot');
      if (Image_Id.src.match("jewly_img/protection.jpg")) {
          Image_Id.src = "jewly_img/protection_1.jpg";
      }
      else {
          Image_Id.src = "jewly_img/protection.jpg";
      }
  }

var snd = new Audio("sound.mp3");
