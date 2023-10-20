const tamañoX = 5;
const tamañoY = 5;

var heroe = {
  posX: 0,
  posY: 0,
  hp: 500,
  ataque: 1,
};

var arrayTablero = [];

// Inicializar el arrayTablero con el tamaño especificado
for (var i = 0; i < tamañoX; i++) {
  arrayTablero[i] = [];
  for (var j = 0; j < tamañoY; j++) {
    arrayTablero[i][j] = "";
  }
}

// Asignar una imagen al héroe en la posición inicial
arrayTablero[heroe.posX][heroe.posY] = "heroe.png";

function actualizarTabla() {
  var tablaHTML = '';

  for (var y = 0; y < tamañoY; y++) {
    tablaHTML += '<tr>';

    for (var x = 0; x < tamañoX; x++) {
      tablaHTML += '<td><img src="' + arrayTablero[x][y] + '"></td>';
    }

    tablaHTML += '</tr>';
  }

  var tableroElement = document.getElementById('tablero');
  if (tableroElement) {
    tableroElement.innerHTML = tablaHTML;
  }
}

//CREAR ENEMIGOS
const NUM_ENEMIGOS = 4;

function posicionAleatoria() {
  var posX, posY;
  do {
    posX = Math.floor(Math.random() * tamañoX);
    posY = Math.floor(Math.random() * tamañoY);
  } while (posX === 0 && posY === 0);

  return { posX: posX, posY: posY };
}

function comprovarPosicionesEnemigos() {
  for (var i = 0; i < NUM_ENEMIGOS; i++) {
    var nuevaPosicion = posicionAleatoria();

    for (var j = 0; j < i; j++) {
      if (
        enemigos[j].posX === nuevaPosicion.posX &&
        enemigos[j].posY === nuevaPosicion.posY
      ) {
        nuevaPosicion = posicionAleatoria();
        j = -1; // Reiniciar el bucle interno
      }
    }

    enemigos.push({
      numEnemigo: i,
      posX: nuevaPosicion.posX,
      posY: nuevaPosicion.posY,
      hp: 130,
      ataque: 70,
    });

    arrayTablero[nuevaPosicion.posX][nuevaPosicion.posY] = "enemigo.png";
  }
}

function insertarEnemigos() {
  for (var i = 0; i < NUM_ENEMIGOS; i++) {
    arrayTablero[enemigos[i].posX][enemigos[i].posY] = "enemigo.png";
  }
  actualizarTabla();
}

var enemigos = [];
comprovarPosicionesEnemigos();
insertarEnemigos();

//COMPROVAR SI SE ENCUENTRA HEROE-ENEMIGO
var enemigoEncontrado;
function comprobarEncuentro() {
  for (var i = 0; i < enemigos.length; i++) {
    if (heroe.posX === enemigos[i].posX && heroe.posY === enemigos[i].posY) {
      enemigoEncontrado = enemigos[i].numEnemigo;
      console.log(enemigoEncontrado);
      return true;
      
    }
  }
  return false;
}

//MOVIMIENTO
document.addEventListener('keydown', function(event) {
  var lastPosX = heroe.posX;
  var lastPosY = heroe.posY;

  switch (event.key) {
    case 'ArrowLeft':
      if (heroe.posX > 0) {
        heroe.posX = heroe.posX - 1;
      }
      break;
    case 'ArrowUp':
      if (heroe.posY > 0) {
        heroe.posY = heroe.posY - 1;
      }
      break;
    case 'ArrowRight':
      if (heroe.posX < tamañoX - 1) {
        heroe.posX = heroe.posX + 1;
      }
      break;
    case 'ArrowDown':
      if (heroe.posY < tamañoY - 1) {
        heroe.posY = heroe.posY + 1;
      }
      break;
    default:
      break;
  }

  arrayTablero[lastPosX][lastPosY] = "";
  arrayTablero[heroe.posX][heroe.posY] = "heroe.png";

  if (comprobarEncuentro()) {
    localStorage.setItem('enemigoEncontrado', enemigoEncontrado);
    window.open("pelea.html", "_blank", "width=700px,height=800px");
  }
  


  actualizarTabla();
});


//----------------------------------PELEA--------------------------------------------

function actualizarHP(hpHeroe, hpEnemigo) {
  var hpHeroeElement = document.getElementById('hpHeroe');
  var hpEnemigoElement = document.getElementById('hpEnemigo');

  if (hpHeroeElement) {
    hpHeroeElement.textContent = hpHeroe + ' PH';
  }

  if (hpEnemigoElement) {
    hpEnemigoElement.textContent = hpEnemigo + ' PH';
  }
}



function movimientoAtaque(color) {
  var imagenHeroe = document.querySelector('.imagen-con-hp img');
  imagenHeroe.classList.add('desplazamiento-derecha');
  setTimeout(function() {
    imagenHeroe.classList.add('parpadeo-' + color);
    setTimeout(function() {
      imagenHeroe.classList.remove('parpadeo-' + color);
      imagenHeroe.classList.add('desplazamiento-izquierda');
      setTimeout(function() {
        imagenHeroe.classList.remove('desplazamiento-derecha');
        imagenHeroe.classList.remove('desplazamiento-izquierda');
      }, 1000);
    }, 500);
  }, 1000);
}

var heroeHP = heroe.hp;
var enemigoEncontrado = localStorage.getItem('enemigoEncontrado');
var enemigoHP = enemigos[enemigoEncontrado].hp;

function ataque1() {
  if (enemigoEncontrado !== undefined) {
    console.log(enemigoEncontrado);
    heroe.ataque = 50;

    if (enemigos[enemigoEncontrado].hp !== undefined) {
      enemigos[enemigoEncontrado].hp -= heroe.ataque;
      console.log(enemigos[enemigoEncontrado].hp);
      actualizarHP(heroe.hp, enemigos[enemigoEncontrado].hp);
      movimientoAtaque('rojo');
    } else {
      console.log("El enemigo no tiene la propiedad 'hp' definida.");
    }
  } else {
    console.log("No se ha encontrado ningún enemigo.");
  }
}

function ataque2() {
  console.log(enemigoEncontrado);
  heroe.ataque = 100;
  enemigos[enemigoEncontrado].hp -= heroe.ataque;
  console.log(enemigos[enemigoEncontrado].hp);
  actualizarHP(heroe.hp, enemigos[enemigoEncontrado].hp);
  movimientoAtaque('rojo');
}

function ataque3() {
  console.log(enemigoEncontrado);
  heroe.ataque = 150;
  enemigos[enemigoEncontrado].hp -= heroe.ataque;
  console.log(enemigos[enemigoEncontrado].hp);
  actualizarHP(heroe.hp, enemigos[enemigoEncontrado].hp);
  movimientoAtaque('lila');
}
