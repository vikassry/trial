function jugclick(){
	var jug = document.getElementById('jug');
	jug.className = "hidden";
	setTimeout(function(){
		jug.className = 'gg';
	}, 1000);
};