var title = "Vue";

var app = new Vue({
    el: '#app',
    data: {
        products: [],
        name: "",
        description: "",
        enough: false,
        results: [],
        diff: "",
    },
    methods: {
        add() {
            this.products.push(
            {
                name: this.name,
                description: this.description,
            });
            this.name = "";
            this.description = "";
            if(this.products.length == 2)
                this.enough = true;
        },
        process() {
            this.results = Array.from(this.products);

            var diff = JsDiff.diffWords(this.products[0].description, this.products[1].description),
                color = "";

            diff.forEach(function(part){
                // green for additions, red for deletions
                // grey for common parts
                console.log(part);

                color = part.added ? 'green' :
                part.removed ? 'red' : 'grey';

                diff = diff + "<span style='color:" + color + "'>" + part.value + "</span>";
            });

            this.diff = diff;
        },
    },
});