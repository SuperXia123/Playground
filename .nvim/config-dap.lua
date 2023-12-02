local dap = require("dap")

dap.configurations.cpp = {
	{
		name = "Playground",
		type = "codelldb",
		request = "launch",
		program = function()
			return vim.fn.getcwd() .. "/build/Playground"
		end,
		cwd = "${workspaceFolder}",
		stopOnEntry = false,
		args = {},
		runInTerminal = true,
		setupCommands = {
			{
				descriptions = "enable pretty printing",
				text = "-enable-pretty-printing",
				ignoreFailsures = false,
			},
		},
	},
}
