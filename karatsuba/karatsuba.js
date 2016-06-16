var add = function(num){
	var sum = 0;
	for(var i=0;i<num.length;i++){
		sum += num[i];		
	}
	return sum;
}

var multiply = function(num){
	var mult = 1;
	for(var i=0;i<num.length;i++){
		mult = mult*num[i];		
	}
	return mult;
}

var substract = function(num){
	var sub = num[0];
	for(var i=1;i<num.length;i++){
		sub = sub-num[i];
	}
	return sub;
}

var addZeros = function(num, extra){	
	for(var i=0;i<num.length;i++){
		
		var numZeros = num[i].toString().split('0').length - 1;
		
		if(extra > numZeros){
			var dif = extra - numZeros - numZeros;
			var zeros = Math.pow(10, dif);			
			num[i] = num[i]*zeros;
			console.log('dif: ' + dif);
		}
	}
	
	return num;
}

var x = 5678;
var y = 1234;
var a = 56;
var b = 78;
var c = 12;
var d = 34;

var step1 = multiply([a, c]);
console.log('Step1: ' + step1);

var step2 = multiply([b, d]);
console.log('Step2: ' + step2);

var step3 = multiply([add([a, b]), add([c, d])]);
console.log('Step3: ' + step3);

var step4 = substract([step3, step2, step1]);
console.log('Step4: ' + step4);

var numWithZeros = addZeros([step1, step4], step2.toString().length);
console.log('numWithZeros: ' + numWithZeros);

var step5 = add([numWithZeros[0] + step2 + numWithZeros[1]]);
console.log('Step5: ' + step5);




