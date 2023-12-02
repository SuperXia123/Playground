local helpers = require("runner.handlers.helpers")

require("runner").set_handler(
	"cpp",
	helpers.choice({
		-- boolean hear specifies wheater a prompt is provided to the user
		["main"] = helpers.shell_handler("zsh build.sh && ./build/Playground", false),
		-- ["build"] = helpers.shell_handler("zsh build.sh", false),
	})
)
