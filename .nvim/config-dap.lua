local dap = require("dap")

dap.configurations.cpp = {
	{
		name = "Playground",
		type = "cppdbg",
		request = "launch",
		program = function()
			return vim.fn.getcwd() .. "/build/Playground"
		end,
		cwd = "${workspaceFolder}",
		stopOnEntry = false,
		args = {},
		-- runInTerminal = true,
		-- setupCommands = {
		-- 	{
		-- 		descriptions = "enable pretty printing",
		-- 		text = "-enable-pretty-printing",
		-- 		ignoreFailsures = false,
		-- 	},
		-- },

	},
}

-- local dap = require("dap")
-- dap.configurations.cpp = {
-- 	{
-- 		name = "launch",
-- 		type = "cppdbg",
-- 		request = "launch",
-- 		program = function()
-- 			return vim.fn.getcwd() .. "/output/ndm_envmodel/ndm_envmodel"
-- 		end,
-- 		cwd = "${workspaceFolder}/output/ndm_envmodel",
-- 		environment = {
-- 			{ name = "LD_LIBRARY_PATH", value = "./lib/auto_common_lib" },
-- 			{ name = "TCMALLOC_SAMPLE_PARAMETER", value = "524288" },
-- 		},
-- 		stopOnEntry = true,
-- 		args = { "-c", "./config/dataflow/ndm_envmodel_process.json", "-w", "./" },
-- 		runInTerminal = false,
-- 	},
-- }
