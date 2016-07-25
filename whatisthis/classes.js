Function.method('new', function(){
	var that = Object.create(this.prototype);
	var other = this.apply(that, arguments);
	return (typeof other === 'object' && other) || that;
});

var Mammal = function(){
	this.name = name;
};

Mammal.prototype.get_name = function(){
	return this.name;
};

Mammal.prototype.says = function(){
	return this.saying || '';
};

var myMammal = new Mammal('Herb the Mammal');
var name = myMammal.get_name();
console.log(name);
