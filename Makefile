.PHONY: clean All

All:
	@echo "----------Building project:[ Queue - Debug ]----------"
	@cd "Queue" && "$(MAKE)" -f  "Queue.mk"
clean:
	@echo "----------Cleaning project:[ Queue - Debug ]----------"
	@cd "Queue" && "$(MAKE)" -f  "Queue.mk" clean
