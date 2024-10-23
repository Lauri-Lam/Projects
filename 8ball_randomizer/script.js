const input = document.getElementById("input")
const output = document.getElementById("output")

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function ask(){
  input.value = ''
  let answers = ['Yes', 'No', 'Maybe', 'FUCK YES!', 'OH HELL NO!', 'KYS', 'LEO ON PASKA LOLIS!']
  output.innerHTML = `${answers[getRandomInt(0, 6)]}`
}