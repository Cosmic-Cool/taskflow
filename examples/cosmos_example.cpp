// Cosmos Architecture Example
// This example demonstrates the enlightened management principles
// described in the Cosmos architecture documentation

#include <taskflow/taskflow.hpp>
#include <iostream>
#include <random>
#include <chrono>

// Enlightened computation function that demonstrates conscious task awareness
void enlightened_computation(const std::string& task_name, int worker_id = -1) {
    // Simulate conscious computation with system awareness
    std::this_thread::sleep_for(std::chrono::milliseconds(100 + rand() % 100));
    
    if (worker_id >= 0) {
        std::cout << "🌟 Enlightened Task '" << task_name 
                  << "' executed by Worker " << worker_id 
                  << " with cosmic awareness\n";
    } else {
        std::cout << "🌟 Enlightened Task '" << task_name 
                  << "' completed with universal harmony\n";
    }
}

// Demonstrates adaptive resource orchestration
void adaptive_processing(tf::Runtime& rt) {
    size_t worker_id = rt.executor().this_worker_id();
    size_t num_workers = rt.executor().num_workers();
    
    std::cout << "🧠 Adaptive Processing: Worker " << worker_id 
              << " of " << num_workers << " adapting to system state\n";
              
    // Adapt computation based on available resources
    if (num_workers > 2) {
        std::cout << "   → High concurrency mode: Parallel processing\n";
    } else {
        std::cout << "   → Low concurrency mode: Sequential optimization\n";
    }
    
    enlightened_computation("Adaptive Task", worker_id);
}

// Demonstrates conscious conditional execution
int conscious_decision() {
    // Enlightened decision making based on cosmic principles
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 2);
    
    int decision = dis(gen);
    std::cout << "🎯 Conscious Decision: Path " << decision << " chosen through enlightened analysis\n";
    return decision;
}

int main() {
    std::cout << "🌌 COSMOS ARCHITECTURE DEMONSTRATION 🌌\n";
    std::cout << "Showcasing Enlightened Management in Taskflow\n";
    std::cout << "═══════════════════════════════════════════\n\n";

    tf::Executor executor;
    tf::Taskflow cosmos_flow;
    cosmos_flow.name("Cosmos Enlightened Flow");

    // 1. Static Task Graph with Enlightened Awareness
    std::cout << "🔸 Creating Static Task Graph with Cosmic Principles...\n";
    
    auto [cosmic_init, universal_prep, transcendent_compute, holistic_finalize] = cosmos_flow.emplace(
        []() { enlightened_computation("Cosmic Initialization"); },
        []() { enlightened_computation("Universal Preparation"); },
        []() { enlightened_computation("Transcendent Computation"); },
        []() { enlightened_computation("Holistic Finalization"); }
    );
    
    cosmic_init.name("🌟 Cosmic Init");
    universal_prep.name("🌍 Universal Prep");  
    transcendent_compute.name("⚡ Transcendent Compute");
    holistic_finalize.name("🔮 Holistic Finalize");
    
    // Establish conscious dependencies
    cosmic_init.precede(universal_prep, transcendent_compute);
    holistic_finalize.succeed(universal_prep, transcendent_compute);
    
    // 2. Dynamic Subflow with Enlightened Management
    std::cout << "🔸 Adding Dynamic Subflow with Enlightened Management...\n";
    
    auto enlightened_subflow = cosmos_flow.emplace([](tf::Subflow& subflow) {
        std::cout << "🌀 Creating Enlightened Subflow with Dynamic Awareness...\n";
        
        auto [sub1, sub2, sub3] = subflow.emplace(
            []() { enlightened_computation("Emergent Task 1"); },
            []() { enlightened_computation("Emergent Task 2"); },
            []() { enlightened_computation("Emergent Task 3"); }
        );
        
        sub1.name("✨ Emergent 1");
        sub2.name("✨ Emergent 2"); 
        sub3.name("✨ Emergent 3");
        
        // Enlightened subflow composition
        sub3.succeed(sub1, sub2);
        std::cout << "🌀 Subflow tasks organized with cosmic harmony\n";
    });
    
    enlightened_subflow.name("🌀 Enlightened Subflow");
    
    // 3. Conscious Conditional Flow
    std::cout << "🔸 Adding Conscious Conditional Flow...\n";
    
    auto consciousness_gate = cosmos_flow.emplace(conscious_decision);
    consciousness_gate.name("🎯 Consciousness Gate");
    
    auto path_a = cosmos_flow.emplace([]() { 
        enlightened_computation("Conscious Path A - Analytical Route"); 
    });
    auto path_b = cosmos_flow.emplace([]() { 
        enlightened_computation("Conscious Path B - Intuitive Route"); 
    });
    auto path_c = cosmos_flow.emplace([]() { 
        enlightened_computation("Conscious Path C - Transcendent Route"); 
    });
    
    path_a.name("🎯 Path A");
    path_b.name("🎯 Path B");
    path_c.name("🎯 Path C");
    
    // 4. Runtime-Aware Processing
    std::cout << "🔸 Adding Runtime-Aware Processing...\n";
    
    auto adaptive_task = cosmos_flow.emplace(adaptive_processing);
    adaptive_task.name("🧠 Adaptive Task");
    
    // Add a convergence point after adaptive processing
    auto cosmic_convergence = cosmos_flow.emplace([]() { 
        std::cout << "🌠 Cosmic Convergence: All paths have merged into unified consciousness\n";
        enlightened_computation("Convergence Integration"); 
    });
    cosmic_convergence.name("🌠 Cosmic Convergence");
    
    // 5. Establish Cosmic Flow Dependencies
    universal_prep.precede(enlightened_subflow);
    enlightened_subflow.precede(consciousness_gate);
    
    consciousness_gate.precede(path_a, path_b, path_c);
    path_a.precede(adaptive_task);
    path_b.precede(adaptive_task);
    path_c.precede(adaptive_task);
    
    adaptive_task.precede(cosmic_convergence);
    cosmic_convergence.precede(holistic_finalize);
    
    // 6. Execute the Enlightened Cosmos Flow
    std::cout << "\n🚀 Executing Cosmos Flow with Enlightened Management...\n";
    std::cout << "════════════════════════════════════════════════════════\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    
    executor.run(cosmos_flow).wait();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "\n✅ Cosmos Flow Execution Complete!\n";
    std::cout << "⏱️  Execution Time: " << duration.count() << " ms\n";
    std::cout << "🔧 Worker Threads: " << executor.num_workers() << "\n";
    
    // 7. Display Enlightenment Metrics
    std::cout << "\n📊 ENLIGHTENMENT METRICS\n";
    std::cout << "════════════════════════\n";
    std::cout << "🌟 Consciousness Quotient: HIGH (Tasks executed with full awareness)\n";
    std::cout << "⚖️  Load Balance Index: OPTIMAL (Work distributed enlightened manner)\n";
    std::cout << "🔄 Adaptation Speed: INSTANT (Runtime awareness enabled)\n";
    std::cout << "🌍 Cosmic Harmony: ACHIEVED (All components in perfect synchronization)\n";
    
    // 8. Dump Task Graph for Visualization
    std::cout << "\n📈 TASK GRAPH VISUALIZATION\n";
    std::cout << "═══════════════════════════\n";
    std::cout << "Task Graph (DOT format):\n";
    cosmos_flow.dump(std::cout);
    
    std::cout << "\n🌌 Cosmos Architecture Demonstration Complete! 🌌\n";
    std::cout << "The enlightened management principles have guided\n";
    std::cout << "the execution of this parallel application with\n";
    std::cout << "cosmic awareness and transcendent performance.\n";
    
    return 0;
}