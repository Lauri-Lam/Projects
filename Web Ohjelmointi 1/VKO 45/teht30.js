function Oppilas(nimi, syntymävuosi, osoite, puhelinnumero) {
  this.nimi = nimi;
  this.syntymävuosi = syntymävuosi;
  this.osoite = osoite;
  this.puhelinnumero = puhelinnumero;

  this.tulosta = function() {
      console.log(`Nimi: ${this.nimi}`);
      console.log(`Syntymävuosi: ${this.syntymävuosi.getFullYear()}`);
      console.log(`Osoite: ${this.osoite}`);
      console.log(`Puhelinnumero: ${this.puhelinnumero}`);
  };

  this.laskeIka = function() {
      const nykyinenVuosi = new Date().getFullYear();
      return nykyinenVuosi - this.syntymävuosi.getFullYear();
  };
}

const oppilas = new Oppilas(
  "Matti Meikäläinen",
  new Date(2000, 0, 1),
  "Esimerkkikatu 123",
  "0401234567"
);

oppilas.tulosta();
console.log(`Ikä: ${oppilas.laskeIka()} vuotta`);