var title = "Vue";

var app = new Vue({
    el: '#app',
    data: {
        products: [],
        name: "",
        incilist: "",
        enough: false,
        diff: false,
        results: [],
        unifiedDiff: "",
        done: false,
        partialDone: false,
    },
    methods: {
        add() {
            this.products.push(
            {
                name: this.name,
                incilist: this.incilist,
            });
            this.name = "";
            this.incilist = "";
            if(this.products.length == 2){
                this.enough = true;
                this.diff = true;
            }
            this.partialDone = true;
        },
        process() {
            var diff = JsDiff.diffWords(this.products[0].incilist, this.products[1].incilist),
                unifiedDiff = "",
                that = this,
                productsOutput = Array.from(that.products);

            diff.forEach(function(part){
                // green for additions, red for deletions
                // grey for common parts

                var color = part.added ? 'green' : part.removed ? 'red' : 'grey';

                productsOutput[0].incilist = that.products[0].incilist.replace(part.value, "<span style='color:" + color + "'>" + part.value + "</span>");
                productsOutput[1].incilist = that.products[1].incilist.replace(part.value, "<span style='color:" + color + "'>" + part.value + "</span>");

                unifiedDiff = unifiedDiff + "<span style='color:" + color + "'>" + part.value + "</span> ";
            });

            this.products = productsOutput;
            this.unifiedDiff = unifiedDiff;
            this.done = true;
        },
    },
});