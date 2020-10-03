function Node(value) {
    this.value = value;
    this.edges = [];
    this.searched = false;
    this.parent = null;
    this.x = -1;
    this.y = -1;
}

Node.prototype.addEdge = function (neighbor) {
    this.edges.push(neighbor);
    neighbor.edges.push(this);
}