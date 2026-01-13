#include <iostream>
#include <string>
#include "httplib.h" // 网络库
#include "json.hpp"  // JSON库

using namespace httplib;
using json = nlohmann::json;

int main() {
    system("chcp 65001"); 
    // 1. 创建服务器实例
    Server svr;

    std::cout << "正在启动服务器..." << std::endl;

    // --- 核心设置：解决跨域问题 (CORS) ---
    // 如果没有这段代码，浏览器会阻止网页访问本地的 C++ 服务器
    svr.set_pre_routing_handler([](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        
        // 如果是预检请求(OPTIONS)，直接返回 OK
        if (req.method == "OPTIONS") {
            res.status = 200;
            return Server::HandlerResponse::Handled;
        }
        return Server::HandlerResponse::Unhandled;
    });

    // --- 接口 1: GET 请求 (查) ---
    // 浏览器访问 http://localhost:8083/hi 时触发
    svr.Get("/hi", [](const Request& req, Response& res) {
        // 构造 JSON 数据
        json data;
        data["message"] = "你好，这是来自 C++ 后端的消息！";
        data["status"] = 200;

        // 发送响应：将 JSON 转为字符串 (.dump())，并告知浏览器这是 JSON 格式
        res.set_content(data.dump(), "application/json");
        
        std::cout << "[GET] /hi 被调用" << std::endl;
    });

    // --- 接口 2: POST 请求 (增) ---
    // 前端提交数据时触发
    svr.Post("/add", [](const Request& req, Response& res) {
        try {
            // 解析前端发来的 JSON 字符串
            auto json_data = json::parse(req.body);
            
            // 获取字段 "name"
            std::string name = json_data["name"];
            std::cout << "[POST] 收到新用户: " << name << std::endl;

            // 返回成功信息
            res.set_content("{\"result\":\"ok\"}", "application/json");
        } catch (...) {
            res.status = 400; // 格式错误
            res.set_content("JSON 解析失败", "text/plain");
        }
    });

    // 2. 启动监听
    std::cout << "服务器运行在 http://localhost:8083" << std::endl;
    svr.listen("0.0.0.0", 8083); // 0.0.0.0 表示允许本机和局域网访问

    return 0;
}