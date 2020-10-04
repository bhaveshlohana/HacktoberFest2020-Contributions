const textInput = 'wodlr helol'
let textInputArr = textInput.split('')

const helloText = 'hello world'

const rs = []

helloText.split('').map((o,) => {
  textInputArr.find((oo) => {
    if (oo === o) {
      rs.push(oo)
      const indexTextInput = textInputArr.indexOf(oo)
      textInputArr.splice(indexTextInput, 1)
      return true
    }
    return false
  })
})
console.log(rs.reduce((prv, cur) => `${prv}${cur}`, ''))
