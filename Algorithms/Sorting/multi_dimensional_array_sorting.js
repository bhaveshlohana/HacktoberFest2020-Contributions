export function sortMultiDimArrayByIndex(inputArr, indexToSort, ascOrDesc){
    inputArr.sort((a, b) => ascOrDesc ? a[indexToSort]-b[indexToSort] : b[indexToSort]-a[indexToSort])
    return inputArr
};