var express = require('express');
var fs = require('fs');
var commentsData = JSON.parse(fs.readFileSync('public/data/comments.json','utf-8')) || [] ;
var router = express.Router();

router.get('/', function(req, res) {
  res.render('index');
});

router.get('/Abeliophyllum', function(req,res){
	res.render('Abeliophyllum');
});

router.get('/Ageratum', function(req,res){
	res.render('Ageratum');
});

router.get('/comments', function(req,res){
	res.render('guest_book');
});

router.get(('/addComment'),function(req,res){
	var date = new Date().toString().slice(0,24);
	var comments = {
				comment: req.query.comment,
				user : 'By: '+ req.query.user,
				time:date
				};
	commentsData.unshift(comments);
	fs.writeFileSync('public/data/comments.json',JSON.stringify(commentsData));
	res.render('commentList',{commentsData:commentsData});
	next();
});

module.exports = router;