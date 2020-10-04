function Graph() {
    this.graph = {};
    this.end = null;
    this.start = null;
}

Graph.prototype.addNode = function (n) {
    // Node into Array
    var name = n.value;
    // Node into "Hash"
    this.graph[name] = n;
}

Graph.prototype.getNode = function (name) {
    var n = this.graph[name];
    return n;
}

Graph.prototype.setStart = function (name) {
    this.start = this.graph[name];
    return this.start;
}

Graph.prototype.setEnd = function (name) {
    this.end = this.graph[name];
    return this.end;
}

Graph.prototype.addCoordinate = function (name, x, y) {
    this.graph[name].x = x;
    this.graph[name].y = y;
}