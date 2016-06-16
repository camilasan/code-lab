var add = function(num){
	var sum = 0;
	for(var i=0;i<num.length;i++){
		sum += num[i];		
	}
	return sum;
}

var addZeros = function(num, extra){	
	for(var i=0;i<num.length;i++){
		
		var numZeros = num[i].toString().split('0').length - 1;
		
		if(extra > numZeros){
			var dif = extra - numZeros - numZeros;
			var zeros = Math.pow(10, dif);			
			num[i] = num[i]*zeros;
		}
	}
	
	return num;
}

var calculate = function(a, b, c, d){
	
	var recur = function(n1, n2){
		return n1*n2;
	}
	
	var step1 = recur(a, c);
	var step2 = recur(b, d);
	var step3 = recur(a+b, c+d);
	var step4 = step3 - step2 - step1;
	var step5 = addZeros([step1, step4], step2.toString().length);
	
	return add(step5) + step2;
}

var total = calculate(56, 78, 12, 34); 
console.log(total);






