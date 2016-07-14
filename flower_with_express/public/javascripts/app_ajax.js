var showComments = function(comments){
	$('#allComments').html(comments);
};

var addComment = function(){
	var comment = $('textarea#comment').val();
	var user = $('#user').val();
	alert(comment);
	alert(user);
	$.ajax("/addComment?comment="+comment+"&user="+user).done(showComments).error(function(err){
		$("#allComments").html(err.responseText);
	});
}; 

$(document).ready(function(){
	$('#allComments').html('');
	$('#add').click(addComment);
});