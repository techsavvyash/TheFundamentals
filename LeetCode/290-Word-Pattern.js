/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    const words = s.split(' ');
    let currChar = 0 ;
    const sMappings = {} ;

    for(let word of words) {
        if(!sMappings[word]) {
            sMappings[word] = currChar ;
            currChar++ ;
        } 
    }

    let finalStr = "";

    for(let word of words) {
        finalStr = finalStr + (sMappings[word]);
    }
    console.log('finalStr: ', finalStr)

    let patString = "" ;
    currChar = 0 ; 
    const newMappings = {} ;
    for(let c of pattern) {
        if(!newMappings[c]) {
            newMappings[c] = currChar++ ;
        }
    }

    for(let c of pattern) {
        patString += newMappings[c];
    }

    return patString == finalStr ;


};