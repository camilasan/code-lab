Function.prototype.method = function (name, func) {
    if (!this.prototype[name]) {
        this.prototype[name] = func;
        return this;
    }
};

Function.method('new', function(){
	var that = Object.create(this.prototype);
	var other = this.apply(that, arguments);
	return (typeof other === 'object' && other) || that;
});

var Mammal = function(name){
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
console.log('myMammal: ' + name);

// var Cat = function (name) {
//     this.name = name;
//     this.saying = 'meow';
// };
// 
// Cat.prototype = new Mammal();
// Cat.prototype.purr = function (n) {
//     var i, s = '';
//     for (i = 0; i < n; i += 1) {
//         if (s) {
//             s += '-';
//         }
//         s += 'r';
//     }
//     return s;
// };
// 
// var myCat = new Cat('Henrietta');
// console.log('myCat: '+ myCat.get_name() + ' ' + myCat.says() + ' ' + myCat.purr(5));

Function.method('inherits', function (Parent) {
    this.prototype = new Parent();
    return this;
});

var Cat = function (name) {
    this.name = name;
}.inherits(Mammal).method('purr', function(n){	
	return 'purr';
}).method('xname', function () {
	return this.name;
});

var myCat = new Cat('Henrietta');
console.log('myCat: '+ myCat.xname() + ' ' + myCat.says() + ' ' + myCat.purr(5));
