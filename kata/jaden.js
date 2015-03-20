String.prototype.toJadenCase = function () {
    words = this.split(" ");
    for(i = 0; i < words.length; i++) {
        words[i] = words[i].substr(0,1).toUpperCase() + words[i].substr(1).toLowerCase();
    }
    return words.join(" ");
};

debug(("How can mirrors be real if our eyes aren't real").toJadenCase()); // How Can Mirrors Be Real If Our Eyes Aren't Real
debug(("Testing this out").toJadenCase()); // Testing This Out
