#!/usr/bin/env node

var Extras = {
	file: {
		path: function(args){
			if (args.length <= 2) {
				Extras.error.logAndExit();
			}else{
				return args[2];
			}
		},		
		open: function(path){
			var fs = require('fs');
			
			if(fs && path){
				return fs.readFileSync(path, 'utf8');
			}else{
				error.logAndExit();;
			}
		}
	},
	error: {
		logAndExit: function(){
			console.log('Something went wrong.');
			console.log('Usage: ' + __filename + ' path_to_file/file.eva');	
			process.exit(-1);		
		}
	}
};
var Eva = {
	tokenizer: {
		read_next: function() {
			read_while(is_whitespace);
			if (stream.eof()) return null;
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
	parser: {
		pos: 0,
		line: 1, 
		col: 0, 
		next: function(){
			var ch = stream.charAt(this.pos++);
			if (ch == "\n") this.line++, this.col = 0; else this.col++;
			return ch;		
		},	
		peek: function(){
			return stream.charAt(this.pos);			
		},
		eof: function(){
			return this.peek() === "";
		},
		croak: function(msg){
			throw new Error(msg + " (" + this.line + ":" + this.col + ")");
		}
	},
	interpreter: function(){
		
	},	
	processStream: function(stream){
		console.log(stream);		
	},
	init: function(args){
		var path = Extras.file.path(args);
		var stream = Extras.file.open(path);
		if(stream) {
			this.processStream(stream);		
		}else{
			Extras.error.logAndExit();
		}
	}
};

Eva.init(process.argv);



