#!/usr/bin/env node

var Eva = function(stream) {	
	return {
		input: stream,
		parser: {
			pos: 0, 
			line: 1, 
			col: 0, 
			next: function(){
				var ch = this.input.charAt(this.parser.pos++);
				if (ch == "\n") this.parser.line++, this.parser.col = 0; else this.parser.col++;
				return ch;		
			},	
			peek: function(){
				return this.input.charAt(this.parser.pos);			
			},
			eof: function(){
				return this.parser.peek() === "";
			},
			croak: function(msg){
				throw new Error(msg + " (" + this.parser.line + ":" + this.parser.col + ")");
			}
		},
		tokenizer: {
			read_next: function() {
				read_while(is_whitespace);
				if (input.eof()) return null;
				var ch = input.peek();
				if (ch == "#") {
					skip_comment();
					return read_next();
				}
				if (ch == '"') return read_string();
				if (is_digit(ch)) return read_number();
				if (is_id_start(ch)) return read_ident();
				if (is_punc(ch)) return {
					type  : "punc",
					value : input.next()
				};
				if (is_op_char(ch)) return {
					type  : "op",
					value : read_while(is_op_char)
				};
				this.parser.input.croak("Can't handle character: " + ch);
			}
		},
		interpreter: {
			
		}
	}
	
};

var File = function(path){
	var fs   = require('fs');
	var content = fs.readFile(path, 'utf8', function(error, data) {
		if (error) throw error;
		return data;
	});
	if(content) return content || '';
}

var Error = function(){
	console.log('Something went wrong.');
	console.log('Usage: ' + __filename + ' path_to_file/file.eva');	
	process.exit(-1);	
}

var Program = function(args){
	if (args.length <= 2) {
		new Error();
	}else{
		var param = args[2];
	}

	if(param){
		var stream = new File(param);
		console.log(stream);
		if(stream){
			var program = new Eva(stream);
			if(program) console.log(program);	
		}
	}else{
		new Error();
	}	
}

new Program(process.argv);



