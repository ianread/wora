{
  "targets": [
    {
      "target_name": "node_wora",
      "sources": [ "binding.cc",
                   "node_calculator.cc" ],
      "libraries": [
        "<!(echo $TARGET_PATH)/libwora.a"
      ],
      "include_dirs": [
      	"<!(echo $SRC_INCLUDES)",
        "<!(echo $NODE_INCLUDES)",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': ['NDEBUG'],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"]
    },
    {
      "target_name": "copy_binary",
      "type":"none",
      "dependencies" : [ "node_wora" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/node_wora.node"],
          "destination": "<!(echo $TARGET_PATH)/"
        }
      ]
    }
  ]
}