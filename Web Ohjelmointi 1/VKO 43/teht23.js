function potenssiin(rivi){
  for (let i = 0; i < rivi; i++){
    let y = 1 + i;
    console.log(`${y} potenssiin ${i} = ${Math.pow(y, i)}`);
  }
}

//testiohjelma
potenssiin(3);