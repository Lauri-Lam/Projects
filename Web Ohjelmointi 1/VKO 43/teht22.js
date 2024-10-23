function kasitteleTaulukko(array) {
  let min = Math.min(...array);
  let max = Math.max(...array);
  let sum = array.reduce((total, value) => { return total + value }, 0);
  let agv = sum / array.length;
  console.log(`Pienin arvo: ${min}`)
  console.log(`Suurin arvo: ${max}`)
  console.log(`Summa: ${sum}`)
  console.log(`Keskiarvo: ${agv.toFixed(2)}`)
}

// testiohjelma
let array = [6 ,2 ,7, 12, 100, 24, 75];
kasitteleTaulukko(array)