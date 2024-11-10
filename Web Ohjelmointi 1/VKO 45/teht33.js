class Arvosana {
  constructor(oppiaine, arvosana, suorituspvm) {
      this.oppiaine = oppiaine;
      
      if (arvosana >= 0 && arvosana <= 10) {
          this.arvosana = arvosana;
      } else {
          throw new Error("Arvosanan täytyy olla välillä 0-10.");
      }
      
      if (suorituspvm instanceof Date) {
          this.suorituspvm = suorituspvm;
      } else {
          throw new Error("Suorituspäivämäärän täytyy olla Date-tyyppiä.");
      }
  }
}

class Oppilas {
  constructor(nimi, syntymävuosi, osoite, puhelinnumero) {
      this._nimi = nimi;
      this._syntymävuosi = syntymävuosi;
      this._osoite = osoite;
      this._puhelinnumero = puhelinnumero;
      this.arvosanat = [];
  }

  get nimi() {
      return this._nimi;
  }

  get syntymävuosi() {
      return this._syntymävuosi;
  }

  get osoite() {
      return this._osoite;
  }

  get puhelinnumero() {
      return this._puhelinnumero;
  }

  set nimi(nimi) {
      this._nimi = nimi;
  }

  set syntymävuosi(syntymävuosi) {
      if (syntymävuosi instanceof Date) {
          this._syntymävuosi = syntymävuosi;
      } else {
          console.error("Syntymävuosi täytyy olla Date-tyyppiä.");
      }
  }

  set osoite(osoite) {
      this._osoite = osoite;
  }

  set puhelinnumero(puhelinnumero) {
      this._puhelinnumero = puhelinnumero;
  }

  tulosta() {
      console.log(`Nimi: ${this.nimi}`);
      console.log(`Syntymävuosi: ${this.syntymävuosi.getFullYear()}`);
      console.log(`Osoite: ${this.osoite}`);
      console.log(`Puhelinnumero: ${this.puhelinnumero}`);
  }

  laskeIka() {
      const nykyinenVuosi = new Date().getFullYear();
      return nykyinenVuosi - this.syntymävuosi.getFullYear();
  }

  lisaaArvosana(oppiaine, arvosana, suorituspvm) {
      try {
          const uusiArvosana = new Arvosana(oppiaine, arvosana, suorituspvm);
          this.arvosanat.push(uusiArvosana);
      } catch (error) {
          console.error(error.message);
      }
  }

  printArvosana() {
      console.log(`Oppilaan ${this.nimi} arvosanat:`);
      this.arvosanat.forEach((arvosanaObj, index) => {
          console.log(
              `Arvosana ${index + 1}: Oppiaine: ${arvosanaObj.oppiaine}, ` +
              `Arvosana: ${arvosanaObj.arvosana}, ` +
              `Suorituspäivämäärä: ${arvosanaObj.suorituspvm.toLocaleDateString()}`
          );
      });
  }

  get arvosanatMuutetullaAsteikolla() {
      return this.arvosanat.map(arvosanaObj => {
          let muutettuArvosana;
          if (arvosanaObj.arvosana <= 2) {
              muutettuArvosana = 1;
          } else if (arvosanaObj.arvosana <= 4) {
              muutettuArvosana = 2;
          } else if (arvosanaObj.arvosana <= 6) {
              muutettuArvosana = 3;
          } else if (arvosanaObj.arvosana <= 8) {
              muutettuArvosana = 4;
          } else {
              muutettuArvosana = 5;
          }
          return {
              oppiaine: arvosanaObj.oppiaine,
              arvosana: muutettuArvosana,
              suorituspvm: arvosanaObj.suorituspvm
          };
      });
  }
}

const oppilas = new Oppilas(
  "Matti Meikäläinen",
  new Date(2000, 0, 1),
  "Esimerkkikatu 123",
  "0401234567"
);

oppilas.lisaaArvosana("Matematiikka", 9, new Date(2023, 5, 10));
oppilas.lisaaArvosana("Englanti", 7, new Date(2023, 6, 15));
oppilas.lisaaArvosana("Fysiikka", 5, new Date(2023, 7, 20));

oppilas.tulosta();
console.log(`Ikä: ${oppilas.laskeIka()} vuotta`);

oppilas.printArvosana();

console.log("Arvosanat muutetulla asteikolla 0-5:");
oppilas.arvosanatMuutetullaAsteikolla.forEach(arvosanaObj => {
  console.log(
      `Oppiaine: ${arvosanaObj.oppiaine}, ` +
      `Arvosana: ${arvosanaObj.arvosana}, ` +
      `Suorituspäivämäärä: ${arvosanaObj.suorituspvm.toLocaleDateString()}`
  );
});