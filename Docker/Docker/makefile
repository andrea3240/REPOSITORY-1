.PHONY: create distclean clean run run-bash test

## Clean
clean:
	@docker container prune
	@docker rmi $$(docker images --filter "dangling=true" -q --no-trunc)

## Create
create:
	@docker build --no-cache -f Dockerfile --target pcs_2025 . -t pcs_2025:1.0.0

## Run
run:
	@docker run --rm -d -it -v ./Data:/home/appuser/Data pcs_2025:1.0.0 /bin/bash -c "./test"

run-bash:
	@docker run --rm -it -v ./Data:/home/appuser/Data pcs_2025:1.0.0 /bin/bash

run-su:
	@docker run --rm -it -u 0 -v ./Data:/home/appuser/Data pcs_2025:1.0.0 /bin/bash
	
## Distclean
distclean:
	@docker container prune
	@docker rmi pcs_2025:1.0.0
	@docker rmi $$(docker images --filter "dangling=true" -q --no-trunc)
	@docker buildx prune -f
