EXAMPLE_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += 

# We can add our module folder to include paths if needed
# This is not actually needed in this case.
CFLAGS_USERMOD += -I$(EXAMPLE_MOD_DIR)
