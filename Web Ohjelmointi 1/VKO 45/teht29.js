class Oppilas {
  constructor(nimi, syntymävuosi, osoite, puhelinnumero) {
      this._nimi = nimi;
      this._syntymävuosi = syntymävuosi;
      this._osoite = osoite;
      this._puhelinnumero = puhelinnumero;
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
}

const oppilas = new Oppilas(
  "Matti Meikäläinen",
  new Date(2000, 0, 1),
  "Esimerkkikatu 123",
  "0401234567"
);

oppilas.tulosta();
console.log(`Ikä: ${oppilas.laskeIka()} vuotta`);