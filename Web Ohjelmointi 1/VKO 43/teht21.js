// Pinta-ala = PII * r ** 2


function laskePintaAla(sade){
  if (sade < 0){
    console.log('Säteen täytyy olla positiivinen!');
    return;
  }

  let ala = Math.PI * Math.pow(sade, 2);
  console.log(`Ympyrän pinta-ala on ${ala.toFixed(2)}`);
}

// testiohjelma
laskePintaAla(5);