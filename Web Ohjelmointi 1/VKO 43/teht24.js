const result = document.getElementById("result");

function palautaNimi(){
  let nimi = prompt('Anna nimesi: ')
  nimi = nimi.toUpperCase();
  result.textContent = nimi;
}

palautaNimi();