

comment=First term projects







push:
	git add *
	git commit -m"$(comment)"
	git push origin main