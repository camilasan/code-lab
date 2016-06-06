var WhatIsThis = {
		value: 0,
		increment: function(inc){
			this.value += typeof inc === 'number' ? inc : 1;
			
		}
};

WhatIsThis.increment();
console.log(WhatIsThis.value);

WhatIsThis.increment(2);
console.log(WhatIsThis.value);

WhatIsThis.add = function(a, b){
	return a + b;
};

var sum = WhatIsThis.add(3, 4);

WhatIsThis.double = function(){
	this.value = this.add(this.value, this.value);	
};

WhatIsThis.double();
console.log(WhatIsThis.value);

console.log(WhatIsThis);

var anotherStatus = {
	status: 'blah'
};

var Blah = function(string){
		this. status = string;
};

Blah.prototype.getStatus = function(){
		return this.status;
};

var myBlah = new Blah('weird');

console.log(myBlah.getStatus());

console.log(WhatIsThis.add.apply(null, [3, 4]));

//bind anotherStatus to this, when this should be only an object of type Blah, but JS is a prototypal inheritance language
console.log(Blah.prototype.getStatus.apply(anotherStatus));


